#pragma once
class TrainerManager
{
private:
	TrainerManager();
	~TrainerManager();

public:
	static TrainerManager& GetInstance()
	{
		static TrainerManager Instance;
		return Instance;
	}
};

#define TRAINER_MANAGER TrainerManager::GetInstance()