#pragma once

#ifdef GINGA_PLATFORM_WINDOWS

extern Ginga::Application* Ginga::CreateApplication();

int main(int argc, char** argv)
{
	Ginga::Log::Init();
	GINGA_CORE_WARN("Initialized Log!");
	GINGA_INFO("Hello!");

	auto app = Ginga::CreateApplication();
	app->Run();
	delete app;
}

#endif
