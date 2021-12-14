workspace "Engine"
	location ".\\sln\\"

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

	syslibdirs {
		".\\devlib\\lib\\",
	}

	includedirs {
		".\\src\\",
		".\\devlib\\include\\",
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
		targetname "game_engine"
		language "c++"
		kind "consoleapp"
		warnings "off"
		
		links {
			"SDL2",
			"SDL2main",
			"SDL2_image",
			"SDL2_mixer",
		}
		
		files {
			".\\src\\**",
		}

		includedirs {
			".\\src\\",
		}