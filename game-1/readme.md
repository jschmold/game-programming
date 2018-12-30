## CMAKE Notes
- Passing CMake settings into a file requires a configure file function call
 - First param is the file with the @TAGS@, second is the output. Suffix it with something to make sense

Abandonment reason:
  I can see there being a lot of overhead with using GLFW as opposed to just using 
  something like Magnum or SFML. Next I am going to try using SFML, and see if that is more in alignment
  with what it is that I want to handle the window operations and such. There's also magnum, but that's
  been less than fun to compile, and it is also unclear if it is just a collection of libs or if it is
  something else.

Things I learned:
 - How to make a basic cmake file
 - Refreshed on how C++ syntactically works
