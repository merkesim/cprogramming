#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
	double x;
	double y;
	double z;
} Vector;

void print_vector(const Vector v);

Vector sum(const Vector v1, const Vector v2);

Vector diff(const Vector v1, const Vector v2);

double dot_product(const Vector v1, const Vector v2);

Vector cross_product(const Vector v1, const Vector v2);

double norm(const Vector v);

int is_unitvector(const Vector v);

Vector unit(const Vector v);

Vector multiplyby_scalar(const Vector v1, const double c);

double angle(const Vector v1, const Vector v2);

double distance(const Vector v1, const Vector v2);

int are_linearly_independent(const Vector v1, const Vector v2, const Vector v3);

int are_orthogonal(const Vector v1, const Vector v2, const Vector v3);


int main ()	{
	Vector v1 = {1, 2, 2}, v2 = {-1, 0, 2}, v3 = {0, 0, 1};
	double k = 2;
	printf("\nv1 = ");
	print_vector(v1);
	printf("\nv2 = ");
	print_vector(v2);
	printf("\nv3 = ");
	print_vector(v3);
	printf("\nv1 + v2 = ");
	print_vector(sum(v1, v2));
	printf("\nv1 - v2 = ");
	print_vector(diff(v1, v2));
	printf("\nk * v1 = ");
	print_vector(multiplyby_scalar(v1, k));
	printf("v1 . v2 = %.2lf\n", dot_product(v1, v2));
	printf("\nv1 x v2 = ");
	print_vector(cross_product(v1, v2));
	printf("| v1 | = %.2lf\n", norm(v1));
	
	if(is_unitvector(v1))
		printf("v1 is a unit vector.\n");
	else
		printf("v1 is not unit vector.\n");

	printf("\nunit( v1 ) = ");
	print_vector(unit(v1));
	printf("angle(v1, v2) = %.2lf\n", angle(v1, v2));
	printf("distance(v1, v2) = %.2lf\n", distance(v1, v2));

	if(are_linearly_independent(v1, v2, v3))
		printf("Vectors are linearly independent.\n");
	else
		printf("Vectors are not linearly independent.\n");
	
	if(are_orthogonal(v1, v2, v3))
		printf("Vectors are orthogonal.\n");
	else
		printf("Vectors are not orthogonal.\n");


 	return 0;
}

void print_vector(const Vector v) {
	printf("(%.2f, %.2f, %.2f)",v.x,v.y,v.z);
};

Vector sum(const Vector v1, const Vector v2) {	
	Vector v;
	
	v.x = v1.x + v2.y;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	
	return v;
};

Vector diff(const Vector v1, const Vector v2){
	Vector v;
	
	v.x = v1.x - v2.y;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	
	return v;
};

Vector multiplyby_scalar(const Vector v1, const double c) {
	Vector v;
	
	v.x = v1.x * c;
	v.y = v1.y * c;
	v.z = v1.z * c;
	
	return v;
};

double dot_product(const Vector v1, const Vector v2) {
	double product;
	product = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;

	return product;

};

Vector cross_product(const Vector v1, const Vector v2) {
	Vector v;
	
	v.x = v1.y*v2.z - v1.z*v2.y;
	v.y = v1.z*v2.x - v1.x*v2.z;
	v.z = v1.x*v2.y - v1.y*v2.x;
	
	return v;
};

double norm(const Vector v) {
	double a;
	
	a = sqrt(pow(v.x,v.x) + pow(v.y,v.y) + pow(v.z,v.z));
	
	return a;
};

int is_unitvector(const Vector v) {
	double b;
	
	b = sqrt(pow(v.x,v.x) + pow(v.y,v.y) + pow(v.z,v.z));
	
	if (b == 1) {
		return true;
	}
	else {
		return false;
	}
};

Vector unit(const Vector v) {
	Vector a; 
	int b;
	b = sqrt(pow(v.x,v.x) + pow(v.y,v.y) + pow(v.z,v.z));
	a.x = v.x/b;
	a.y = v.y/b;
	a.z = v.z/b;
	
	return a;
};

double angle(const Vector v1, const Vector v2) {
	double a;
	double b;
	
	a = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z / (sqrt(pow(v1.x,v1.x) + pow(v1.y,v1.y) + pow(v1.z,v1.z)) * sqrt(pow(v2.x,v2.x) + pow(v2.y,v2.y) + pow(v2.z,v2.z)));
	b = acos(a);
	
	return b;
};

double distance(const Vector v1, const Vector v2) {
	Vector a;
	
	a.x = v1.x - v2.x;
	a.y = v1.y - v2.y;
	a.z = v1.z - v2.z;
	
	double dist = sqrt(pow(a.x,a.x)+pow(a.y,a.y)+pow(a.z,a.z));
	
	return dist;
};

int are_linearly_independent(const Vector v1, const Vector v2, const Vector v3) {
	int det;
	
	det = ((v1.x*v2.y*v3.z)+(v1.y*v2.z*v3.x)+(v1.z*v2.x*v3.y)-((v3.x*v2.y*v1.z)+(v3.y*v2.z*v1.x)+(v3.z*v2.x*v1.y)));
	if(det == 0)
		return true;
	else
		return false;
};

int are_orthogonal(const Vector v1, const Vector v2, const Vector v3) {
	int v12 = v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
	int v13 = v1.x*v3.x + v1.y*v3.y + v1.z*v3.z;
	int v23 = v2.x*v3.x + v2.y*v3.y + v2.z*v3.z;
	
	if ( v12 == 0 && v13 == 0 && v23 == 0)
		return true;
	else 
		return false;	
};


