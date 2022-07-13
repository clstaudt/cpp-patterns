#include <string>

class Money
 {
	private:
	  	int m_amount;
	  	std::string m_currency;

	public:
		Money(int amount, const std::string& currency) 
			: m_amount(amount), m_currency(currency)
		{
		}
			
		int amount() const
		{
			return m_amount;
		}

		std::string getCurrency() const
		{
			return m_currency;
		}

		// overload == operator for equals comparison
		bool operator==(const Money&m ) const
		{
			return     m.getCurrency() == m_currency 
					&& m.amount() == m_amount;
		}	
		
		Money* add(Money& m) 
		{
			return new Money(amount() + m.amount(), getCurrency());
		}

};
