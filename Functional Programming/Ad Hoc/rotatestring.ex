defmodule Rotatestring do
	def rotate(s), do: rotate(s, 0, String.length(s)) 
	def rotate(s,i,n) do
		if i < n do		
			t = String.slice(s, 1, n) <> String.first(s)
			IO.write(t <> " ")
			rotate(t,i+1, n)
		end
	end
end

n = IO.gets("") |> String.strip() |> String.to_integer()
for _ <- 1..n do
	s = IO.gets("") |> String.strip()
	Rotatestring.rotate(s)
	IO.write("\n")
end
