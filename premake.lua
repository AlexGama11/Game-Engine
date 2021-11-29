worworkspace "Engine"
	location ".\\build\\"

	targetdir "%{wks.location}\\bin\\%{cfg.buildcfg}\\"
	objdir "%{wks.location}\\obj\\%{cfg.buildcfg}\\%{prj.name}\\"
	buildlog "%{wks.location}\\obj\\%{cfg.buildcfg}\\%{prj.name}.log"

	largeaddressaware "on"
	editandcontinue "off"
	staticruntime "on"

	systemversion "latest"
	characterset "ascii"
	architecture "x86"
	warnings "extra"

	buildoptions {
		"/std:c++20",
	}

	includedirs {
		".\\src\\",
	}

	platforms {
		"x86",
	}

	configurations {
		"Release",
		"Debug",
	}

	configuration "Release"
		defines "NDEBUG"
		optimize "debug"
		runtime "debug"
		symbols "on"

	configuration "Debug"
		defines "DEBUG"
		optimize "debug"
		runtime "debug"
		symbols "on"

	project "Game Engine"
		targetname "Game Engine
		kind "consoleapp"
		warnings "off"
		
		files {
			".\\Game Engine\\**",
		}

		includedirs {
			".\\Game Engine\\",
            ".\\Devlib\include\",
            ".\\Devlib\bin\",
            ".\\Devlib\lib\",
		}