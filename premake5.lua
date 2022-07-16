workspace "Filters"
	architecture "x64"
	configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Filters"
	kind "ConsoleApp"
	language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	includedirs { "src" }

	files { "src/**.h", "src/**.cpp" }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

	filter "system:Windows"
        cppdialect "C++17"
        defines { "WINDOWS" }