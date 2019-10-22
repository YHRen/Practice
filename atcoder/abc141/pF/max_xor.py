# https://stackoverflow.com/a/27470710/3838215
# David's solution
def max_xor(iterable):
    array = list(iterable)  # make it a list so that we can iterate it twice
    if not array:  # special case the empty array to avoid an empty max
        return 0
    x = 0
    w = [{i} for i, _ in enumerate(array)]
    s = set() # selected
    while True:
        y = max(array)
        i = array.index(y)
        if y == 0: return x, s
        if x^y > x :
            x ^= y
            s ^= w[i]
        w[i] ^= w[i]
        array[i] = 0
        for j, z in enumerate(array): 
            if z^y < z:
                z ^= y
                w[j] ^= w[i]

        # x = max(x, x ^ y)
        # eliminate
        # array = [min(z, z ^ y) for z in array] 

def print_binary(lst, fmt):
    for i, x in enumerate(lst):
        print(fmt.format(i,x))

def eval_selection(lst, idx):
    res = 0
    for i in idx: res ^= lst[i]
    return res

if __name__=="__main__":
    lst = [3, 6, 5]
    print_binary(lst, "{}: {:04b}")
    val, sel = max_xor(lst)
    print(val, sel, eval_selection(lst,sel))
    print("------------")
    lst = [23, 36, 66, 65]
    print_binary(lst, "{}: {:07b}")
    val, sel = max_xor(lst)
    print(val, sel, eval_selection(lst,sel))
    print("------------")
    lst  =  [1008288677408720767, 539403903321871999, 1044301017184589821,
             215886900497862655, 504277496111605629, 972104334925272829,
             792625803473366909, 972333547668684797, 467386965442856573,
             755861732751878143, 1151846447448561405, 467257771752201853,
             683930041385277311, 432010719984459389, 319104378117934975,
             611451291444233983, 647509226592964607, 251832107792119421,
             827811265410084479, 864032478037725181]
    print_binary(lst, "{}: {:064b}")
    val, sel = max_xor(lst)
    print(val, sel, eval_selection(lst,sel))
    print("------------")
