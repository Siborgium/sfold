# sfold

## SFolD - Siborgium's fold

### What is it
Small header-only C++17 folding library.

### Installation
Clone this repository or download it manually, then just `#include` `.../sfold/fold`.

### Why
I created this repository due to few simple things. First, I need *not verbose* analog of functional `fold`, `reduce`, and so on. STL contains such functions, but they are ugly, verbose, they was made in very strange and *special* way. And, for unknown reason, there is no such functions for parameter packs. So, here we are.

### To do
I have many ideas, such as providing predefined basic functions to user.
Speaking of folds only, there is still no right fold function for parameter packs, and this is an issue. I will fix it as soon as possible.

### Content
**This repository is developed, so this list can be edited (especially expanded) any time**
 - `fold` - this function takes a binary function, start value and pair of iterators. It performs left fold on every argument of provided sequence and returns a result. You can perform a right fold by using pair reverse iterators. 
 - `foldl` - this function takes a binary function, start value and parameter pack. It performs left fold on every argument of provided parameter pack and returns a result. 

### Examples
#### Basic rules
Every fold function takes different count of parameters, but core is simple:
 - The first parameter is always a binary function.
 - The second parameter is always start value.
You can use currying function to bind the binary function, if you wish to perform interesting functional things.

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
//Searching the greatest element for guaranteed O(N) complexity
using sfd::foldl;
std::cout << foldl([](auto &a, auto &b){ return a > b ? a : b; }, std::numeric_limits<int>::lowest(), 1, 3, 4, 7, 10, 21, 2, 4, 5); //21
```
