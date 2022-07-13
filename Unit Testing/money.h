#include <string>
#include <stdexcept>

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
			if(getCurrency() == m.getCurrency())
				return new Money(amount() + m.amount(), getCurrency());
			else
				return nullptr;
		}

		// name is just different for demonstration purposes
		Money* add_with_ex(Money& m) 
		{
			if(getCurrency() == m.getCurrency())
				return new Money(amount() + m.amount(), getCurrency());
			else
			{
				throw std::invalid_argument("Currencies do not match.");
			}
			return nullptr;
		}

};
