#include "MainMenuState.h"
#include "LevelState.h"
#include "ExitState.h"
#include "TextElement.h"
#include "Renderer.h"
#include "LevelSelectState.h"
#include "Game.h"
MainMenuState::MainMenuState()
{
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::Enter()
{
	TextElement* playText = new TextElement("Press 'a' to play a run");
	TextElement* selectText = new TextElement("Press 's' to select level");
	TextElement* exitText = new TextElement("Press 'd' to exit");
	TextElement* menuText = new TextElement("Breakout Clone");
	TextElement* creditText = new TextElement("By: Scott Buglass, Matthew Dudley, and Mitchell Hodzen");
	menuText->SetX((Renderer::GetInstance().GetScreenWidth() / 2) - (menuText->GetWidth() / 2));
	menuText->SetY((Renderer::GetInstance().GetScreenHeight() / 2) - (menuText->GetHeight() / 2));

	int commandY = Renderer::GetInstance().GetScreenHeight() - 200;
	int spacing = 100;
	playText->SetX((Renderer::GetInstance().GetScreenWidth() / 2) - (playText->GetWidth()) - spacing/2);
	playText->SetY(commandY);
	exitText->SetX((Renderer::GetInstance().GetScreenWidth() / 2) - (exitText->GetWidth() / 2));
	exitText->SetY(commandY + 50);

	selectText->SetX((Renderer::GetInstance().GetScreenWidth() / 2) + spacing / 2);
	selectText->SetY(commandY);
	textList.push_back(menuText);
	textList.push_back(selectText);
	textList.push_back(exitText);
	textList.push_back(playText);
	textList.push_back(creditText);
}
void MainMenuState::Exit()
{
}
GameState* MainMenuState::Update()
{
	//if we should transition then transition
	//Otherwise delegate to base class
	return GameState::Update();
}
GameState* MainMenuState::APressed()
{
	Game::GetInstance().SetGameType(Game::GameType::RUN);
	return GameState::Transition(new LevelState(1));
}
GameState* MainMenuState::SPressed()
{
	Game::GetInstance().SetGameType(Game::GameType::SELECT);
	return GameState::Transition(new LevelSelectState());
}
GameState* MainMenuState::DPressed()
{
	return GameState::Transition(new ExitState());
}
