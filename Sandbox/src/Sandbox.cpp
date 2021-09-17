#include <Ginga.h>

class ExampleLayer : public Ginga::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		GINGA_INFO("ExampleLayer::Update");
	}

	void OnEvent(Ginga::Event& event) override
	{
		GINGA_TRACE("{0}", event);
	}
};

class Sandbox : public Ginga::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Ginga::ImGuiLayer());
	}
	~Sandbox()
	{

	}
};

Ginga::Application* Ginga::CreateApplication()
{
	return new Sandbox();
}