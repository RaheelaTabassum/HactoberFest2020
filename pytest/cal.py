import numbers, sys, json


class CalculatorError(Exception):
	"""An Exception"""
	pass


# Raises error
# class Calculator:
#
# 	def my_add(self, a, b):
# 		try:
# 			return a+b
# 		except TypeError:
# 			raise CalculatorError()


class Calculator:

	def add(self, a, b):
		self._check_operand(a)
		self._check_operand(b)
		return a+b

	def sub(self, a, b):
		return a-b

	def mul(self, a, b):
		return a*b

	def div(self, a, b):
		if b == 0:
			raise CalculatorError("cant divide by 0")
		return a/b

	def _check_operand(self, val):
		if not isinstance(val, numbers.Number):
			raise CalculatorError(f"{val} is not a number")


if __name__ == '__main__':
	print("Lets calculate")
	c = Calculator()
	operations = [c.add, c.sub, c.mul, c.div]
	while True:
		# Menu
		for i, op in enumerate(operations, start=1):
			print(f"{i}: {op.__name__}")
		print("q: quit")

		operation = input("Pick a number:: ")
		if operation == 'q':
			sys.exit()

		a = float(input("What is a: "))
		b = float(input("What is b: "))

		try:
			print(operations[int(operation)-1](a, b))
		except CalculatorError as ex:
			print(ex)



def read_json(some_file):
	with open(some_file, 'r') as f:
		return json.load(f)