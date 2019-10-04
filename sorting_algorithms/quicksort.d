import std.stdio;

T[] quicksort( T )( T[] slice )
{
    import std.algorithm : filter;
    import std.array : array;
    if( slice.length == 0 ) return [];
    return 
        quicksort( slice.filter!( v => v < slice[0] ).array ) ~ 
        slice[0] ~ 
        quicksort( slice.filter!( v => v > slice[0] ).array );        
}

void main()
{
    auto values = [9, 2, 5, 6, 4, 3, 7, 10, 1, 12, 8, 11];
	values.quicksort.writeln;
}

