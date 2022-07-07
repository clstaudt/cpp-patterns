class SeatImpl 
{
	public:
		virtual int GetPosition() = 0;
		virtual void SetPosition(int) = 0;
};

class AimSeat : public SeatImpl
{
	public:
		int GetPosition() override
		{
			// call to the AIM simulator 
			return 0;
		}
};

class SARTSeat : public SeatImpl 
{
	public:
		int GetPosition() override
		{
			// call to the SART seat simulator
			return 0;
		}
};

class Stub : public SeatImpl 
{
	public:
		int GetPosition() override
		{
			return 5;
		}
};

// for compiler reasons
int main() 
{
	return 0;
}




