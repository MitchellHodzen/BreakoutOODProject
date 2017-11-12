#include "LevelSelectScoreState.h"
#include "LevelState.h"
#include "MainMenuState.h"
#include "Renderer.h"
#include "TextElement.h"
LevelSelectScoreState::LevelSelectScoreState(int level, int score) : ScoreState(level, score)
{
}


LevelSelectScoreState::~LevelSelectScoreState()
{
}

void LevelSelectScoreState::Enter()
{
	std::cout << "Entering Level select score State" << std::endl;
	TextElement* replayText = new TextElement("Press 'a' to replay level");
	TextElement* menuText = new TextElement("Press 's' to return to main menu");
	///TextElement* nextText = new TextElement("Press 's' to continue to next level");
	int commandX = Renderer::GetInstance().GetScreenWidth() / 2;
	int spacing = 50;
	replayText->SetY((Renderer::GetInstance().GetScreenHeight() / 2) + spacing);
	replayText->SetX(commandX - replayText->GetWidth() / 2);
	menuText->SetY((Renderer::GetInstance().GetScreenHeight() / 2) + 2 * spacing);
	menuText->SetX(commandX - menuText->GetWidth() / 2);
	//nextText->SetY((Renderer::GetInstance().GetScreenHeight() / 2) + 2 * spacing);
	//nextText->SetX(commandX - nextText->GetWidth() / 2);
	textList.push_back(menuText);
	textList.push_back(replayText);
	//textList.push_back(nextText);
	ScoreState::Enter();
}
void LevelSelectScoreState::Exit()
{
	std::cout << "Exiting level select score State" << std::endl;
}
GameState* LevelSelectScoreState::APressed()
{
	//replay level
	return GameState::Transition(new LevelState(level));
}
GameState* LevelSelectScoreState::SPressed()
{
	//return to menu
	return GameState::Transition(new MainMenuState());
}
