#define DISALLOW_COPY_ASSIGN(A)  A(const A&); \
		A& operator=(const A&);

class Lock{
private:
	CRITICAL_SECTION &m_cs;
public:
	Lock(CRITICAL_SECTION cs): m_cs(cs) {
		cs.lock();
	}
	~Lock(){
		cs.unlock();
	}
};
class Singleton{
private:
	DISALLOW_COPY_ASSIGN(Singleton)
	Singleton(){}
public:
	static Singleton* pInstance;
	static Singleton* instance(){
		if(pInstance == 0){
			Lock lock(cs);
			if(pInstance == 0)
				pInstance = new Singleton();
		}
		return pInstance;
	}
};

Singleton* Singleton::pInstance = 0;
