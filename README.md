# FastMortonKeys

##Warning, deprecated repo

Like every program with "Fast" in their name, this code is not that fast and you shouldn't use this in production.

If you're still looking for morton code, you can have a look at these two repos : 
- https://github.com/aavenel/mortonlib which encode/decode morton keys using intrinsics and provides some functions for morton arithmetic.
- https://github.com/Forceflow/libmorton which is a more complete study of different methods for morton encoding/decoding.

##Introduction

Compute morton keys blazingly fast using a look-up table.
The look-up table is automatically generated at compile-time thanks to template metaprogramming.

Thanks to Jeroen Baert for initial inspiration and his great blog post explaining morton keys (http://www.forceflow.be/2013/10/07/morton-encodingdecoding-through-bit-interleaving-implementations/)
