import pytest
from cal import Calculator, CalculatorError, read_json
# from fibo import fibonacci
"""
For test to get executed automatically, files
should start with test_* and write test under
functions that start with test*.

To search for files starting with test_ or _test.py
and it will execute all the tests in that. The
search will start from the current working directory
and continue below recursively
$ pytest

For searching of test files in
a specific directory
$ pytest /path/to/directory

Execute a specific test by
$ pytest <file>::<test_name>

Execute all tests in a class
$ pytest <file>::<test_class>

Execute a particular test in a class
$ pytest <file>::<test_class>::<test_name>

This is simiar to membership label in c++

More verbose
$ pytest . -v

To only see the tests and do not execute
$ pytest . --collect-only

Tests are divided into three phases -
Arrange - c = Calculator()
Act - ans = c.add(2, 3)
Assert - assert ans == 5

pytest raise helps in raising custom issues
"""

def test_add():
	c = Calculator()
	result = c.add(3, 4)
	assert result == 7


'''
What if we want to test many features with different inputs?
Problem with below implementation is if single iteration fails,
it will abort rest of the operations
'''
def test_add_range():
	c = Calculator()
	for i in range(10):
		assert c.add(i, 2) == i+2


'''
New Approach - pytest parameterize
Run as individual tests
'a, b, expected' are automatically converted to variables
'''
@pytest.mark.parametrize(
	'a, b, expected', [
		(1, 1, 2),
		(2, 1, 3),
		(3, 1, 4),
		(4, 1, 5),
		(5, 1, 6),
		(6, 1, 7),
		(7, 1, 8),
	]
)
def test_add_parameterize(a, b, expected):
	c = Calculator()
	assert c.add(a, b) == expected


def test_add_weird():
	c = Calculator()

	# Raise error when any one is string
	with pytest.raises(CalculatorError) as context: 
		result = c.add('10', 20)

	assert str(context.value) == '10 is not a number'


def test_sub():
	c = Calculator()
	result = c.sub(3, 4)
	assert result == -1


def test_mul():
	c = Calculator()
	result = c.mul(3, 4)
	assert result == 12


def test_div():
	c = Calculator()
	result = c.div(3, 10)
	assert result == 3/10


class TestBale:

	def test_div_weird(self):
		c = Calculator()

		with pytest.raises(CalculatorError):
			result = c.div(3, 0)


'''
Fixtures for setup and teardown of certain tests
First define fixture
'''

def test_fixture(my_fixture):
	assert my_fixture == 42 


'''
Fixture 1
capsys will capture the logs
redirect output in capsys

caplogger for logger in logger module
Can be used in send to aws file
'''
def test_cap(capsys):
	print('hello') # going to stdout
	print('out')
	out, err = capsys.readouterr()
	assert 'hello' in out


'''
Fixture 2
Monkey Patching - dynamically swap behaviour of the 
expensive function
Add a fake names
'''
def test_monkeypatch(monkeypatch):
	c = Calculator()
	def fake_add(a, b):
		return 42

	monkeypatch.setattr(c, "add", fake_add)
	assert c.add(2, 3) == 42


'''
Fixture 3
'''
def test_tmpdir(tmpdir):
	# Feed content
	file = tmpdir.join('superman.txt')
	file.write('{"hello": "world"}')

	# Read the data
	result = read_json(str(file))
	assert result["hello"] == "world"


'''
Fixture 4
Multiple fixtures at the same time
'''
def test_many_fixtures(capsys, capture_print):
	print('more')
	out, err = capsys.readouterr()
	assert out == 'hello\nmore\n'










