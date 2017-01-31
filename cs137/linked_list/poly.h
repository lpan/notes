struct poly {
  int power;
  double coeff;
  struct poly *next;
};

typedef struct poly poly;

poly *poly_init(void);

poly *poly_insert(poly *p, int power, double coeff);

double poly_eval(poly* p, double x);

poly *poly_del(poly *p);
