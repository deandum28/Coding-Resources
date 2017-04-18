void add(int A[], int B[])
{
      int i, t = 0;
      for (i=1; i<=A[0] || i<=B[0] || t; i++, t/=10)
              A[i] = (t += A[i] + B[i]) % 10;
      A[0] = i - 1;
}

void mul(int A[], int B) // big * small
{
      int i, t = 0;
      for (i = 1; i <= A[0] || t; i++, t /= 10)
              A[i] = (t += A[i] * B) % 10;
      A[0] = i - 1;
}

void mul(int A[], int B[]) // big * big
{
      int i, j, t, C[NR_CIFRE];
      memset(C, 0, sizeof(C));
      for (i = 1; i <= A[0]; i++)
      {
              for (t=0, j=1; j <= B[0] || t; j++, t/=10)
                      C[i+j-1]=(t+=C[i+j-1]+A[i]*B[j])%10;
              if (i + j - 2 > C[0]) C[0] = i + j - 2;
      }
      memcpy(A, C, sizeof(C));
}

void sub(int A[], int B[])
{
      int i, t = 0;
      for (i = 1; i <= A[0]; i++) {
              A[i] -= ((i <= B[0]) ? B[i] : 0) + t;
              A[i] += (t = A[i] < 0) * 10;
      }
      for (; A[0] > 1 && !A[A[0]]; A[0]--);
}

void div(int A[], int B)
{
      int i, t = 0;
      for (i = A[0]; i > 0; i--, t %= B)
              A[i] = (t = t * 10 + A[i]) / B;
      for (; A[0] > 1 && !A[A[0]]; A[0]--);
}

int mod(int A[], int B)
{
      int i, t = 0;
      for (i = A[0]; i > 0; i--)
              t = (t * 10 + A[i]) % B;
      return t;
}