int exponente(int base, int exp) {
    if (base == 0) {
        return 0;
    } else if (base == 1) {
        return 1;
    } else if (exp == 0) {
        return 1;
    } else if (exp == 1) {
        return base;
    } else {
        int res = 1;

        for (int i = 1; i <= exp; i++) {
            res *= base;
        }

        return res;
    }
}
