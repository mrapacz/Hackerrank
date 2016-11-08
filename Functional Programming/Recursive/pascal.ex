defmodule Pascal do
	def factorial(n), do: factorial(n, 1)
 	def factorial(0, acc), do: acc
 	def factorial(n, acc), do: factorial(n-1, acc*n)

	def triangle(n), do: triangle(0,n-1)
	def triangle(row, n) do
		if row <= n do
			triangle(row, n, 0)
		end
	end
	def triangle(row, n, col) do
		if col <= row do
			a = factorial(row)
			b = factorial(col)
			c = factorial(row-col)
			element = div(a,b*c)

			IO.write(Integer.to_string(element) <> " ")
			triangle(row, n, col+1)
		else
			IO.write("\n")
			triangle(row+1, n)
		end
	end 

end
n = IO.gets("") |> String.strip() |> String.to_integer
Pascal.triangle(n)