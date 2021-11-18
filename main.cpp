#include <cctype>
#include <iostream>
#include <string>
int main()
{

    std::string message {};
    std::string Alphabet {
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+,./;'[]\\<>?:{}|-="
    }; // 91 characters
    std::string key { "ZXCVBNM,./';LKJHGFDSRAQWETYUIOP[]\\=-0987654321!@#$%^&*()_+|}{:?><zaqxwcdevfrtgbnhyujmklsiop" };

    std::cout << "Enter a secret message: ";
    getline(std::cin, message);


    std::string encrypted_message {};
    std::string decrypted_message {};

    // Encryption

    for(char c : message) {
        size_t position = Alphabet.find(c);
        {
            if(position != std::string::npos) {
                char new_char { key.at(position)}; 
                encrypted_message += new_char;
            } else {
                encrypted_message += c;
            }
        }
    }
    
    std::cout << encrypted_message << std::endl;
    
   // Decryption
    
    for(char c : encrypted_message){
        size_t position = key.find(c);
        {
            if(position != std::string::npos){
                char replacement{Alphabet.at(position)};
                decrypted_message += replacement;
                
            }else{
                decrypted_message += c;
            }
        }
    }
    
    std::cout << decrypted_message << std::endl;

    

    return 0;
}
