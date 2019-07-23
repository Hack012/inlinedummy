#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>

using namespace eosio;

CONTRACT inlinedummy: public contract {
    public:
    using contract::contract;

    ACTION dummy(name user) {
        require_auth (user);
        print("dummy");
        action(
            permission_level(user, "active"_n), //permission
            get_self(),//contract name,
            "dummytwo"_n, //action name,
            std::make_tuple(user)//parameters 파라미터 자체가 순서를 가진다.
            //튜플을 만든다(튜플: 순서를 가지는 배열)
        ).send();        
    }
    ACTION dummytwo(name user) {
        require_auth(user);
        print("dummy two, ", user);  
    }

    private:
};