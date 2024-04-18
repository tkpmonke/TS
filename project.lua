workspace "TS"
   configurations { "Debug", "Release" }
   architecture "x86_64"

project "TS"
   kind "ConsoleApp"
   language "C++"
   files { "**.h", "**.cpp" }
   removefiles { "tools/**", "projects/**" }
   targetdir "bin"

   libdirs { "libs" }
   links { "glfw3", "glew32s", "opengl32"}

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"