workspace "Ginga"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release", 
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {
	["GLFW"] = "%{prj.name}/vendor/GLFW/include", 
	["Glad"] = "%{prj.name}/vendor/Glad/include",
	["ImGui"] = "%{prj.name}/vendor/imgui",
	["glm"] = "%{prj.name}/vendor/glm"
}

include "Ginga/vendor/GLFW"
include "Ginga/vendor/Glad"
include "Ginga/vendor/imgui"


project "Ginga"
	location "Ginga"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "GIngapch.h"
	pchsource "Ginga/src/GIngapch.cpp"

	files
	{
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}", 
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	defines
	{
		"GINGA_PLATFORM_WINDOWS",
		"GINGA_BUILD_DLL",
		"GLFW_INCLUDE_NONE"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "system.windows"

		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines "GINGA_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "GINGA_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "GINGA_DIST"
		buildoptions "/MD"
		optimize "On"

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Ginga/vendor/spdlog/include",
		"Ginga/src",
		"%{IncludeDir.glm}"
	}
	
	links
	{
		"Ginga"
	}

	defines
	{
		"GINGA_PLATFORM_WINDOWS"
	}

	filter "system.windows"

		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines "GINGA_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "GINGA_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "GINGA_DIST"
		buildoptions "/MD"
		optimize "On"