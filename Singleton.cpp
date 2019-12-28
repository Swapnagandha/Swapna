Singleton* Singleton::getInstance()
{
    if (instance == 0)
    {
        instance = new Singleton();
    }

    return instance;
}

Singleton::Singleton()
{}

int main()
{
    //new Singleton(); // Won't work
    Singleton* s = Singleton::getInstance(); // Ok
    Singleton* r = Singleton::getInstance(); same instance

    /* The addresses will be the same. */
    std::cout << s << std::endl;
    std::cout << r << std::endl;
}
