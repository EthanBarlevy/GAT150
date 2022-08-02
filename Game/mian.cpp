#include "engine.h"
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	vl::InitializeMemory();

	vl::SetFilePath("../Assets");

	// initialize engine
	vl::g_renderer.Initialize();
	vl::g_inputSystem.Initialize();
	vl::g_audioSystem.Initialize();

	// create window
	vl::g_renderer.CreateWindow("Gaming", 500, 500);
	vl::g_renderer.setClearColor(vl::Color{ 0, 0, 0, 255 });

	// this will be moved later
	std::shared_ptr<vl::Texture> texture = std::make_shared<vl::Texture>();
	texture->Create(vl::g_renderer, "file_10.bmp");

	{
		bool quit = false;
		while (!quit)
		{
			// update
			vl::g_time.Tick();
			vl::g_inputSystem.Update();
			vl::g_audioSystem.Update();

			if (vl::g_inputSystem.GetKeyDown(vl::key_escape)) quit = true;

			//render
			vl::g_renderer.BeginFrame();

			vl::g_renderer.Draw(texture, { 250, 250 }, 0);

			vl::g_renderer.EndFrame();
		}
	}

	vl::g_inputSystem.Shutdown();
	vl::g_renderer.Shutodwn();
	vl::g_audioSystem.Shutdown();
}