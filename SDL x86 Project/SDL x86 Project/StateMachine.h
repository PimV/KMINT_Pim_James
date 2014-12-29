template <class entity_type>
class StateMachine
{
private:
	//a pointer to the agent that owns this instance
	entity_type* m_pOwner;
	BaseState<entity_type>* m_pCurrentState;
	//a record of the last state the agent was in
	BaseState<entity_type>* m_pPreviousState;
	//this state logic is called every time the FSM is updated
	BaseState<entity_type>* m_pGlobalState;
public:
	StateMachine(entity_type* owner):m_pOwner(owner),
		m_pCurrentState(NULL),
		m_pPreviousState(NULL),
		m_pGlobalState(NULL)
	{}
	//use these methods to initialize the FSM
	void SetCurrentState(BaseState<entity_type>* s){m_pCurrentState = s;}
	void SetGlobalState(BaseState<entity_type>* s) {m_pGlobalState = s;}
	void SetPreviousState(BaseState<entity_type>* s){m_pPreviousState = s;}
	//call this to update the FSM
	void Update()const
	{
		//if a global state exists, call its execute method
		if (m_pGlobalState) m_pGlobalState->execute(m_pOwner);
		//same for the current state
		if (m_pCurrentState) m_pCurrentState->execute(m_pOwner);
	}
	//change to a new state
	void ChangeState(BaseState<entity_type>* pNewState)
	{
		assert(pNewState &&
			"<StateMachine::ChangeState>: trying to change to a null state");
		//keep a record of the previous state
		m_pPreviousState = m_pCurrentState;
		//call the exit method of the existing state
		m_pCurrentState->exit(m_pOwner);
		//change state to the new state
		m_pCurrentState = pNewState;
		//call the entry method of the new state
		m_pCurrentState->enter(m_pOwner);
	}
	//change state back to the previous state
	void RevertToPreviousState()
	{
		ChangeState(m_pPreviousState);
	}
	//accessors
	BaseState<entity_type>* CurrentState() const {
		return m_pCurrentState;
	}
	BaseState<entity_type>* GlobalState() const {
		return m_pGlobalState;
	}
	BaseState<entity_type>* PreviousState() const {
		return m_pPreviousState;
	}
	//returns true if the current state’s type is equal to the type of the
	//class passed as a parameter.
	bool isInState(const BaseState<entity_type>& st)const;
};