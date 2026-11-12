# C++ Style

Custom settings for clang-format.

This repository contains a curated `.clang-format` configuration file to be shared across my
projects.  If you like the style feel free to use it.


# Usage

Just copy the `.clang-format` file to the root directory of you project (or to your home folder) and
run `clang-format`.  Optionally you can download the repo if you wish.  That way you can change what
you want and keep a history of your changes.  That's it.


# The style

Below there are some examples of how your code will look after formatting.  I'll try to keep these
examples updated, time permitting.


### Rules and examples

Braces are on their own lines.  Tabs for indenting so you can adjust how your editor displays the
code by adjusting the tab size.  Do you prefer 2 spaces, 4, 8?  Maybe 3?  That's all possible thanks
to the magic of **Tabs**!  Oh and they only occupy **1 character** no matter their size!  Brilliant.

Spaces between parenthesis and their content, if any.  Align pointer (*) and reference (&) to the
left.  They're part of the type.

```cpp
#include <print>


auto main(int argc, char* argv[]) -> int
{
        std::println( "That's more like it!" );

        return 0;
}
```


Pointer/reference alignment example.

```cpp
auto sum_all(const std::vector<int>& nums) -> double
{
        // TODO: I haven't decided on initialisation style yet. But I quite like this one.
        double sum {0};

        for (auto& n : nums)
        {
            sum += n;
        }

        return sum;
}
```
