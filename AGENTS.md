## Agent skills

### Issue tracker

Issues and PRDs are tracked in this repository's GitHub Issues. See `docs/agents/issue-tracker.md`.

### Triage labels

Triage uses the five default canonical label names. See `docs/agents/triage-labels.md`.

### Domain docs

Domain documentation uses a single-context layout. See `docs/agents/domain.md`.

## Local workspace hygiene

Keep repository-scoped working state discoverable and manageable from this repository:

- Put isolated checkouts or copies under `.agents/workspaces/<task-id>/`.
- Put short-lived diagnostic files under `.agents/tmp/<task-id>/`.
- If a repository-scoped cache must be redirected, place it under `.agents/cache/<task-id>/`.
- Keep xmake's project cache and build outputs at their repository-local defaults: `.xmake/` and `build/`.
- Do not place repository-scoped intermediates in arbitrary user-profile or application-owned directories, including Codex visualization directories. The only allowed external location for disposable temporary files is `%TEMP%`.
- Prefer `git worktree` or a copy operation that explicitly excludes the destination when creating an isolated workspace inside the repository; never recursively copy the repository into one of its own descendants without that exclusion.
- Remove task-owned temporary directories when the task finishes. If cleanup is blocked, report the exact remaining path and its purpose.
