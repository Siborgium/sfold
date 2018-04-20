## SFolD - Siborgium's fold

### What is it
Small header-only C++17 folding library.

### Installation
Clone this repository or download it manually, then just `#include ".../sfold/fold"`.

### Why
I created this repository for a few simple things. First, I need *non-verbose* analog of functional `fold` (also called `reduce`), and so on. STL contains such functions, but they are ugly, verbose and made in very strange and *special* way.  And, for unknown reason, there is no such functions for parameter packs. So, here we are.

### To do
I have many ideas, such as providing predefined basic functions to user.
Speaking of folds only, there is still no right fold function for parameter packs, and this is an issue. I will fix it as soon as possible.

### Content
**This repository is being developed currently, so this list can be edited (especially expanded) any time**
 - `fold` - this function takes a binary function, a start value and pair of iterators. It performs left fold on every argument of provided sequence and returns a result. You can perform a right fold by using pair reverse iterators. 
 - `foldl` - this function takes a binary function, a start value and parameter pack. It performs left fold on every argument of provided parameter pack and returns a result.

### Examples
#### Basic rules
Every fold function takes different count of parameters, but the core is simple:
 - The first parameter is always a binary function.
 - The second parameter is always the start value.


#### Left fold on vector
```cpp
//Evaluating product
using sfd::fold;
std::vector data = { 1, 2, 3, 4, 5 };
std::cout << fold([](auto &a, auto &b){ return a * b; }, 1, data.begin(). data.end()); //120
```

#### Right fold on vector
```cpp
//Concatenating words
using sfd::fold;
std::vector<std::string> data = { "!", "world", "Hello, " };
std::cout << fold([](auto &a, auto &b) { return a + b; }, std::string(), data.rbegin(), data.rend()); //Hello, world!
```

#### Left fold on parameter pack
```cpp
//Searching the greatest element with guaranteed O(N) complexity
using sfd::foldl;
std::cout << foldl(
                [](auto &a, auto &b){ return a > b ? a : b; },
                std::numeric_limits<int>::lowest(),
                1, 3, 4, 7, 10, 21, 2, 4, 5); //21
```

#### Using <functional> functional objects as binary function
```cpp
//Evaluatuing multiple boolean conditions
using sfd::foldl;
std::cout << foldl(std::logical_or(), true, false, false, false) << '\n'; //true
```
