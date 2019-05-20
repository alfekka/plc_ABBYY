#include "exception.h"

void yep()
{
    THROW( new CVZException() );
}

void nope()
{
    std::cout << "yep" << '\n';
    yep();
}


int main()
{
    TRY
    {
        TRY
        {
            nope();
        }
        CATCH( CVZException, e )
        {
            std::cout << e->GetMessage() << " 1 " << '\n';
        }
        CATCH( CException, e )
        {
            std::cout << e->GetMessage() << " 2 " << '\n';
        }
        ENDTRYCATCH;
    }
    CATCH( CException, e )
    {
        std::cout << e->GetMessage() << " 3 " << '\n';
    }
    ENDTRYCATCH;

    std::cout << "nope" << '\n';
    return 0;
}