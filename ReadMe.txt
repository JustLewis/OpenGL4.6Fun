First, go to project and retarget the solution or you'll get some annoying errors.

Another possible error you'll have is the debug x64 at the top next to local windows debugger. 
If you're running the 32 bit version of GLFW, you'll have a linker error, so change x64 to x86 and that'll fix it.

This project doesn't include the libraries from the first video, so you'll need to set them up - https://www.youtube.com/watch?v=D_BzUhhQAfc
