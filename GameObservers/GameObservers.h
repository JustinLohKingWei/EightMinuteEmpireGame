class GameObservers             // observer class
{
public:
    ~GameObservers();
    virtual void Update()=0;

protected:
    GameObservers();
};