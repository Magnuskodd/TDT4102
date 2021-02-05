def isFibonacciNumber(n):
	a = 0;
	b = 1;
	
	while b < n:
		temp = b
		b += a
		a = temp

	return bool(b==n)

print(isFibonacciNumber(3))
print(isFibonacciNumber(7))
print(isFibonacciNumber(13))
print(isFibonacciNumber(20))
		