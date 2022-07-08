#include <string>
#include <stdexcept>
#include <vector>
#include <regex>

namespace StringHelper
{
    std::vector<std::string> split(const std::string& input, const std::string& regex) 
    {
        std::regex re(regex);
        std::sregex_token_iterator
            first{input.begin(), input.end(), re, -1},
            last;
        return {first, last};
    }

    std::string rtrim(const std::string& s)
    {
        static const std::regex tws{"[[:space:]]*$", std::regex_constants::extended};
        return std::regex_replace(s, tws, "");
    }
}

class Cipher
{
    public:
        virtual std::string encryptWord(const std::string&, unsigned int) = 0;
        virtual std::string decryptWord(const std::string&, unsigned int) = 0;
};

class Transpose : public Cipher
{
    public:
        std::string encryptWord(const std::string& word, unsigned int key) override
        {
            return word;
        };
        std::string decryptWord(const std::string& word, unsigned int key) override
        {
            return word;
        }
};

class Ceasar : public Cipher
{
    public:
        std::string encryptWord(const std::string& word, unsigned int key) override
        {
            return word;
        };
        std::string decryptWord(const std::string& word, unsigned int key) override
        {
            return word;
        }
};

class Encryption 
{
    protected:
        Cipher* imp; // Bridge
    public:
	    virtual std::string encrypt(const std::string&, unsigned int) = 0;
	    virtual std::string decrypt(const std::string&, unsigned int) = 0;	
};

class PersonalEncryption : public Encryption
{
    public:
        PersonalEncryption() 
        { 
            imp = new Transpose(); 
        } 

        ~PersonalEncryption() 
        { 
            if(imp != nullptr)
            {
                delete imp;
                imp = nullptr;
            }
        } 
	    std::string encrypt(const std::string& string, unsigned int key) override
        {  
            std::string result = "";
            auto words = StringHelper::split(string, "[[:space:]]");
            for(auto const& word: words) 
            {
                result += imp->encryptWord(word, key) + " ";
            }
            return StringHelper::rtrim(result);
        }
	    std::string decrypt(const std::string& string, unsigned int key) override
        {
            std::string result = "";
            auto words = StringHelper::split(string, "[[:space:]]");
            for(auto const& word: words) 
            {
                result += imp->decryptWord(word, key) + " ";
            }
            return StringHelper::rtrim(result);
        }
};

class EnterpriseEncryption : public Encryption
{
    public:
        EnterpriseEncryption() 
        { 
            imp = new Ceasar(); 
        } 

        ~EnterpriseEncryption() 
        { 
            if(imp != nullptr)
            {
                delete imp;
                imp = nullptr;
            }
        } 
	    std::string encrypt(const std::string& string, unsigned int key) override
        {  
            std::string result = "";
           
            if(key < 10)
            {
                throw std::invalid_argument("Insecure Key! Encryption aborted");
            }
           
            auto words = StringHelper::split(string, "[[:space:]]");
            for(auto const& word: words) 
            {
                result += imp->encryptWord(word, key) + " ";
            }
            return StringHelper::rtrim(result);
        }
	    std::string decrypt(const std::string& string, unsigned int key) override
        {
            std::string result = "";
            auto words = StringHelper::split(string, "[[:space:]]");
            for(auto const& word: words) 
            {
                result += imp->decryptWord(word, key) + " ";
            }
            return StringHelper::rtrim(result);;
        }
};

// for compiler reasons
int main()
{
    return 0;
}