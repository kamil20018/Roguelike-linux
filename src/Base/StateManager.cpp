#include "StateManager.h"




StateManager::StateManager() : add(false), replace(false), remove(false), swap(false) {

}

StateManager::~StateManager() {

}

void StateManager::AddState(std::shared_ptr<State> toAdd, bool replace) {
	this->add = true;
	this->newState = std::move(toAdd);
	this->replace = replace;
}

void StateManager::PopCurrent() {
	this->remove = true;
}

void StateManager::ProcessStateChange() {

	if (this->remove and not this->stateStack.empty()) {

		this->stateStack.pop_back();
		if (!stateStack.empty()) {
			stateStack.back()->Start();
		}
		this->remove = false;
	}

	if (this->add) {
		if (this->replace and not stateStack.empty()) {
			this->stateStack.pop_back();
		}

		if (not this->stateStack.empty()) {
			this->stateStack.back()->Pause();
		}

		this->stateStack.push_back(std::move(this->newState));

		this->stateStack.back()->Init();
		this->stateStack.back()->Start();
		this->add = false;

	}

	if (this->swap and this->stateStack.size() >= 2) {
		this->swap = false;
		int swapIndex = (int)this->stateStack.size() - 2;
		std::shared_ptr<State> temp = this->stateStack[swapIndex];
		this->stateStack.erase(this->stateStack.begin() + swapIndex);
		this->stateStack.push_back(temp);
	}

}

void StateManager::SwapPrevious() {
	this->swap = true;
}

std::shared_ptr<State>& StateManager::GetCurrent() {
	return stateStack.back();
}