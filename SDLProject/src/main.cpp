#include "Application.h"

int main()
{
	Application* App = new Application;
	App->Run();

	delete App;

	return 0; //Same as EXIT_SUCCESS
}