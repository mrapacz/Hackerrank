defmodule Replicatelist do
    def replicate(n) do
	case IO.gets "" do
		eof -> :ok
		element -> 
			String.duplicate(element, n) |> IO.write
			replicate n
	end
    end
end
n = IO.gets("") |> String.strip |> String.to_integer
Replicatelist.replicate n
