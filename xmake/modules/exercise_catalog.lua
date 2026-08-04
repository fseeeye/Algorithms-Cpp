import("core.base.json")

local _roots = {
    algorithms = {
        namespace = "Algorithm",
        metadataPrefix = "Algorithm",
        targetPrefix = "algo",
        tag = "algorithm",
        title = "Algorithms",
        vsGroup = "Algorithms",
        indexed = true,
        order = 1
    },
    data_structures = {
        namespace = "DataStructure",
        metadataPrefix = "DataStructure",
        targetPrefix = "ds",
        tag = "data_structure",
        title = "Data Structures",
        vsGroup = "DataStructures",
        indexed = true,
        order = 2
    },
    reviews = {
        namespace = "Review",
        metadataPrefix = "Review",
        targetPrefix = "review",
        tag = "review",
        title = "Reviews",
        vsGroup = "Reviews",
        indexed = false,
        order = 3
    }
}

local _allowedMetadataKeys = {
    difficulty = true,
    id = true,
    kind = true,
    name = true,
    tip = true,
    url = true
}

local function _slashes(value)
    return value:gsub("\\", "/")
end

local function _split_path(value)
    local parts = {}
    for part in _slashes(value):gmatch("[^/]+") do
        table.insert(parts, part)
    end
    return parts
end

local function _trimmed_string(value, field, metadataPath, allowEmpty)
    if type(value) ~= "string" then
        raise("%s: '%s' must be a string", metadataPath, field)
    end
    value = string.trim(value)
    if not allowEmpty and value == "" then
        raise("%s: '%s' must not be empty", metadataPath, field)
    end
    return value
end

local function _is_lower_snake(value)
    return value:match("^[a-z0-9_]+$") ~= nil
        and value:sub(1, 1) ~= "_"
        and value:sub(-1) ~= "_"
        and not value:find("__", 1, true)
end

local function _problem_id_is_valid(value)
    return value:match("^[A-Z][A-Z0-9]*$") ~= nil and value:find("%d") ~= nil
end

local function _url_is_valid(value)
    return value == "" or value:match("^https?://[^%s]+$") ~= nil
end

local function _natural_chunks(value)
    local chunks = {}
    local index = 1
    while index <= #value do
        local digit = value:sub(index, index):match("%d") ~= nil
        local finish = index
        while finish + 1 <= #value
            and (value:sub(finish + 1, finish + 1):match("%d") ~= nil) == digit do
            finish = finish + 1
        end
        table.insert(chunks, {value = value:sub(index, finish):lower(), digit = digit})
        index = finish + 1
    end
    return chunks
end

local function _natural_less(left, right)
    local leftChunks = _natural_chunks(left)
    local rightChunks = _natural_chunks(right)
    for index = 1, math.min(#leftChunks, #rightChunks) do
        local leftChunk = leftChunks[index]
        local rightChunk = rightChunks[index]
        if leftChunk.value ~= rightChunk.value then
            if leftChunk.digit and rightChunk.digit then
                local leftNumber = tonumber(leftChunk.value)
                local rightNumber = tonumber(rightChunk.value)
                if leftNumber ~= rightNumber then
                    return leftNumber < rightNumber
                end
                return #leftChunk.value < #rightChunk.value
            end
            return leftChunk.value < rightChunk.value
        end
    end
    return #leftChunks < #rightChunks
end

local function _markdown_cell(value)
    return value:gsub("[\r\n]+", " "):gsub("|", "\\|")
end

local function _humanize(slug)
    local words = {}
    for word in slug:gmatch("[^_]+") do
        table.insert(words, word == "io" and "IO" or word:sub(1, 1):upper() .. word:sub(2))
    end
    return table.concat(words, " ")
end

function roots()
    return _roots
end

function normalize_slug(rawSlug)
    if rawSlug:find("[/\\]") or rawSlug:find("%.%.") then
        raise("unsafe slug '%s': path separators and '..' are not allowed", rawSlug)
    end
    if rawSlug:find("[^A-Za-z0-9 _%-]") then
        raise("unsafe slug '%s': use letters, digits, spaces, '-' or '_'", rawSlug)
    end

    local slug = rawSlug:gsub("(%u+)(%u%l)", "%1_%2")
    slug = slug:gsub("(%l)(%u)", "%1_%2")
    slug = slug:gsub("(%d)(%u)", "%1_%2")
    slug = slug:gsub("[ _%-]+", "_"):lower()
    slug = slug:gsub("^_+", ""):gsub("_+$", "")
    if slug == "" then
        raise("--slug must contain at least one letter or digit")
    end
    return slug
end

function pascal_case(slug)
    local words = {}
    for word in slug:gmatch("[^_]+") do
        table.insert(words, word == "io" and "IO" or word:sub(1, 1):upper() .. word:sub(2))
    end
    return table.concat(words)
end

function humanize(slug)
    return _humanize(slug)
end

function domain_for_relative_path(relativePath)
    local parts = _split_path(relativePath)
    local rootName = parts[1]
    local domain = rootName and _roots[rootName]
    if not domain then
        raise("Exercise path must be inside algorithms, data_structures or reviews: %s", relativePath)
    end
    return rootName, domain
end

function resolve_root(projectDir, rawRoot)
    local absoluteRoot = path.absolute(rawRoot, projectDir)
    local relativeRoot = _slashes(path.relative(absoluteRoot, projectDir))
    local rootName, domain = domain_for_relative_path(relativeRoot)
    if relativeRoot ~= rootName and relativeRoot:sub(1, #rootName + 1) ~= rootName .. "/" then
        raise("--root must be inside algorithms, data_structures or reviews: %s", rawRoot)
    end
    if not os.isdir(absoluteRoot) then
        raise("--root does not exist or is not a directory: %s", relativeRoot)
    end
    return absoluteRoot, relativeRoot, rootName, domain
end

function normalize_problem_id(rawId)
    local id = string.trim(rawId):upper()
    if not _problem_id_is_valid(id) then
        raise("--id must be a compact Problem ID such as LC215, HJ02, LCOF45 or CF123A")
    end
    return id
end

function normalize_difficulty(rawDifficulty)
    if not rawDifficulty or string.trim(rawDifficulty) == "" then
        return ""
    end
    local normalized = string.trim(rawDifficulty):lower()
    local values = {easy = "Easy", medium = "Medium", hard = "Hard"}
    if not values[normalized] then
        raise("--difficulty must be Easy, Medium or Hard")
    end
    return values[normalized]
end

function validate_url(rawUrl)
    local url = rawUrl and string.trim(rawUrl) or ""
    if not _url_is_valid(url) then
        raise("--url must be an absolute http:// or https:// URL")
    end
    return url
end

function metadata_json(metadata)
    local function encode_string(value)
        local encoded, errors = json.encode(value)
        if not encoded then
            raise("cannot encode Exercise metadata: %s", errors)
        end
        return encoded:gsub("\\/", "/")
    end

    local keys = {"kind", "id", "name", "difficulty", "tip", "url"}
    local lines = {"{"}
    for index, key in ipairs(keys) do
        local encoded = encode_string(metadata[key] or "")
        local suffix = index < #keys and "," or ""
        table.insert(lines, string.format("  %s: %s%s", encode_string(key), encoded, suffix))
    end
    table.insert(lines, "}")
    return table.concat(lines, "\n") .. "\n"
end

function validate_metadata(metadataPath, projectDir)
    local metadata, errors = json.loadfile(metadataPath)
    if not metadata then
        raise("%s: %s", _slashes(path.relative(metadataPath, projectDir)), errors)
    end
    if type(metadata) ~= "table" then
        raise("%s: metadata root must be an object", metadataPath)
    end

    local relativeMetadataPath = _slashes(path.relative(metadataPath, projectDir))
    for key, _ in pairs(metadata) do
        if not _allowedMetadataKeys[key] then
            raise("%s: unknown field '%s'", relativeMetadataPath, key)
        end
    end

    local kind = _trimmed_string(metadata.kind, "kind", relativeMetadataPath, false)
    if kind ~= "problem" and kind ~= "template" then
        raise("%s: 'kind' must be problem or template", relativeMetadataPath)
    end
    local id = _trimmed_string(metadata.id, "id", relativeMetadataPath, false)
    local name = _trimmed_string(metadata.name, "name", relativeMetadataPath, false)
    local difficulty = metadata.difficulty == nil and ""
        or _trimmed_string(metadata.difficulty, "difficulty", relativeMetadataPath, true)
    local tip = metadata.tip == nil and ""
        or _trimmed_string(metadata.tip, "tip", relativeMetadataPath, true)
    local url = metadata.url == nil and ""
        or _trimmed_string(metadata.url, "url", relativeMetadataPath, true)

    if difficulty ~= "" and difficulty ~= "Easy" and difficulty ~= "Medium" and difficulty ~= "Hard" then
        raise("%s: 'difficulty' must be Easy, Medium, Hard or empty", relativeMetadataPath)
    end
    if not _url_is_valid(url) then
        raise("%s: 'url' must be an absolute http:// or https:// URL", relativeMetadataPath)
    end

    local exerciseDir = path.directory(metadataPath)
    local relativeDir = _slashes(path.relative(exerciseDir, projectDir))
    local rootName, domain = domain_for_relative_path(relativeDir)
    local directoryName = path.basename(exerciseDir)
    local slug
    local identity
    if kind == "problem" then
        if not _problem_id_is_valid(id) then
            raise("%s: Problem 'id' must be compact uppercase letters and digits and contain a digit", relativeMetadataPath)
        end
        local prefix = id:lower() .. "_"
        if directoryName:sub(1, #prefix) ~= prefix then
            raise("%s: directory must start with '%s'", relativeMetadataPath, prefix)
        end
        slug = directoryName:sub(#prefix + 1)
        identity = id
    else
        local prefix = domain.targetPrefix .. "_"
        if directoryName:sub(1, #prefix) ~= prefix then
            raise("%s: Template directory must start with '%s'", relativeMetadataPath, prefix)
        end
        slug = directoryName:sub(#prefix + 1)
        identity = pascal_case(slug)
        local expectedId = domain.metadataPrefix .. "." .. identity
        if id ~= expectedId then
            raise("%s: Template 'id' must be '%s'", relativeMetadataPath, expectedId)
        end
    end
    if not _is_lower_snake(slug) then
        raise("%s: Exercise slug must be lower snake_case", relativeMetadataPath)
    end

    local relativeParent = _slashes(path.relative(path.directory(exerciseDir), path.join(projectDir, rootName)))
    if relativeParent == "." then
        relativeParent = ""
    end
    local categoryParts = _split_path(relativeParent)
    local tags = {kind, domain.tag}
    for _, category in ipairs(categoryParts) do
        table.insert(tags, category)
    end
    if kind == "problem" then
        table.insert(tags, id:lower())
    end

    return {
        category = relativeParent,
        difficulty = difficulty,
        directory = exerciseDir,
        directoryName = directoryName,
        domain = domain,
        id = id,
        identity = identity,
        kind = kind,
        metadataPath = metadataPath,
        name = name,
        namespaceName = string.format("AlgoCpp::%s::%s::%s",
            kind == "problem" and "Problem" or "Template", domain.namespace, identity),
        relativeDirectory = relativeDir,
        rootName = rootName,
        slug = slug,
        tags = "[" .. table.concat(tags, "][") .. "]",
        tip = tip,
        url = url
    }
end

function scan(projectDir)
    local exercises = {}
    local byDirectory = {}
    local byId = {}
    local byTarget = {}

    for rootName, _ in pairs(_roots) do
        local rootDir = path.join(projectDir, rootName)
        for _, metadataPath in ipairs(os.files(path.join(rootDir, "**", "exercise.json"))) do
            local exercise = validate_metadata(metadataPath, projectDir)
            local comparableDirectory = exercise.directory:lower()
            if byDirectory[comparableDirectory] then
                raise("duplicate Exercise metadata directory: %s", exercise.relativeDirectory)
            end
            local comparableId = exercise.id:lower()
            if byId[comparableId] then
                raise("duplicate Exercise ID '%s': %s and %s",
                    exercise.id, byId[comparableId].relativeDirectory, exercise.relativeDirectory)
            end
            local comparableTarget = exercise.directoryName:lower()
            if byTarget[comparableTarget] then
                raise("duplicate Exercise target '%s': %s and %s",
                    exercise.directoryName, byTarget[comparableTarget].relativeDirectory, exercise.relativeDirectory)
            end
            local tests = os.files(path.join(exercise.directory, "*_test.cpp"))
            if #tests == 0 then
                raise("%s: Exercise metadata requires at least one colocated *_test.cpp",
                    exercise.relativeDirectory)
            end
            exercise.tests = tests
            byDirectory[comparableDirectory] = exercise
            byId[comparableId] = exercise
            byTarget[comparableTarget] = exercise
            table.insert(exercises, exercise)
        end
    end

    for rootName, _ in pairs(_roots) do
        local rootDir = path.join(projectDir, rootName)
        for _, testPath in ipairs(os.files(path.join(rootDir, "**", "*_test.cpp"))) do
            local exerciseDir = path.directory(testPath):lower()
            if not byDirectory[exerciseDir] then
                raise("%s: Exercise Test requires colocated exercise.json",
                    _slashes(path.relative(testPath, projectDir)))
            end
        end
    end

    table.sort(exercises, function (left, right)
        if left.domain.order ~= right.domain.order then
            return left.domain.order < right.domain.order
        end
        if left.category ~= right.category then
            return _natural_less(left.category, right.category)
        end
        if left.kind ~= right.kind then
            return left.kind == "template"
        end
        return _natural_less(left.id, right.id)
    end)
    return exercises
end

function render_index(projectDir, exercises)
    exercises = exercises or scan(projectDir)
    local lines = {}
    local currentRoot
    local currentCategory
    for _, exercise in ipairs(exercises) do
        if exercise.domain.indexed then
            if currentRoot ~= exercise.rootName then
                if #lines > 0 then
                    table.insert(lines, "")
                end
                table.insert(lines, "### " .. exercise.domain.title)
                currentRoot = exercise.rootName
                currentCategory = nil
            end
            if currentCategory ~= exercise.category then
                table.insert(lines, "")
                local categoryTitle = exercise.category ~= "" and _humanize(exercise.category:gsub("/", "_"))
                    or exercise.domain.title
                table.insert(lines, "#### " .. categoryTitle)
                table.insert(lines, "")
                table.insert(lines, "| ID | Name | Difficulty | Tip |")
                table.insert(lines, "| :-- | :--- | :--------- | :-- |")
                currentCategory = exercise.category
            end
            local link = "./" .. _slashes(exercise.relativeDirectory)
            table.insert(lines, string.format("| %s | [%s](%s) | %s | %s |",
                _markdown_cell(exercise.id), _markdown_cell(exercise.name), link,
                _markdown_cell(exercise.difficulty), _markdown_cell(exercise.tip)))
        end
    end
    return table.concat(lines, "\n")
end

function index_contents(projectDir, exercises)
    local readmePath = path.join(projectDir, "README.md")
    local readme, errors = io.readfile(readmePath)
    if not readme then
        raise("cannot read README.md: %s", errors)
    end
    local startMarker = "<!-- exercise-index:start -->"
    local endMarker = "<!-- exercise-index:end -->"
    local startFirst, startLast = readme:find(startMarker, 1, true)
    local endFirst, endLast = readme:find(endMarker, 1, true)
    if not startFirst or not endFirst or startFirst >= endFirst
        or readme:find(startMarker, startLast + 1, true)
        or readme:find(endMarker, endLast + 1, true) then
        raise("README.md must contain exactly one ordered exercise-index marker pair")
    end

    local rendered = render_index(projectDir, exercises)
    local replacement = startMarker .. "\n" .. rendered .. "\n" .. endMarker
    return readme:sub(1, startFirst - 1) .. replacement .. readme:sub(endLast + 1), readme
end

function update_index(projectDir, checkOnly)
    local exercises = scan(projectDir)
    local expected, current = index_contents(projectDir, exercises)
    if expected == current then
        return false
    end
    if checkOnly then
        raise("README Exercise Index is stale; run 'xmake index'")
    end
    local readmePath = path.join(projectDir, "README.md")
    io.writefile(readmePath, expected)
    return true
end

function check_new_collision(projectDir, directoryName, id)
    local comparableDirectoryName = directoryName:lower()
    local comparableId = id:lower()
    for rootName, _ in pairs(_roots) do
        local rootDir = path.join(projectDir, rootName)
        for _, directory in ipairs(os.dirs(path.join(rootDir, "**"))) do
            local existingName = path.basename(directory):lower()
            if existingName == comparableDirectoryName then
                raise("Exercise target already exists: %s", directoryName)
            end
        end
    end
    for _, exercise in ipairs(scan(projectDir)) do
        if exercise.id:lower() == comparableId then
            raise("Exercise ID already exists: %s", id)
        end
    end
end
