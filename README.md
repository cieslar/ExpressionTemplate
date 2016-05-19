# ExpressionTemplate
A small exercise in expression templates.

I needed to speed up computations that were based on very simple structure:

```c++
struct Cartesian
{
        double fX;
        double fY;
        double fZ;
};
```

I ended up with an expression templates (see `TECartesian.cpp`) that do the job quite well.

## Compilation and testing
Just do
```
make compile
make test
```
or
```
make
```
which do them both.

For my very budget-orientated laptop and *gcc version 4.8.4* the tests yield:
```
Structure: 71815
Expression template: 449024
TStruct/TTempl: 0.159936

./exe_O2
Structure: 27448
Expression template: 7023
TStruct/TTempl: 3.9083

./exe_cpp11
Structure: 75392
Expression template: 445826
TStruct/TTempl: 0.169106

./exe_O2_cpp11
Structure: 27409
Expression template: 7024
TStruct/TTempl: 3.90219

./exe_O3_cpp11
Structure: 27264
Expression template: 557
TStruct/TTempl: 48.9479
```
The times are in [micro seconds].

