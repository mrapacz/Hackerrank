defmodule StringMingling do
	def mingle(a,b) do
			Enum.zip(a,b) |> Enum.reduce("", fn {x,y}, acc-> acc <> x <> y end)
		end	
end

a = IO.gets("") |> String.strip |> String.split("")
b = IO.gets("") |> String.strip |> String.split("")
IO.puts(StringMingling.mingle(a,b))