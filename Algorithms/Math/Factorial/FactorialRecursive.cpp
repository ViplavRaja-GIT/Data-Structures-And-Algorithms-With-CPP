int FactorialRecursive(int number)
{
    return number > 1 ? number * FactorialRecursive(number-1) : 1;
}