# Dynamic Array

Impl : **based on static array**.

1. Create a static array with an initial capacity.
2. Add elements to the underlying static array, keeping track of the number of elements.
3. If adding another element will exceed the capacity, then create a new static array with twice the capacity and copy the original elements into it.

Reference : 

- -https://github.com/williamfiset/Algorithms/blob/master/src/main/java/com/williamfiset/algorithms/datastructures/dynamicarray/IntArray.java
- UnrealEngine\Engine\Source\Runtime\Core\Public\Containers\Array.h