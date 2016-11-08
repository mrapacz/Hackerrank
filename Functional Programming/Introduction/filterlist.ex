defmodule Filterlist do
    def filter(delimiter) do
		case IO.gets "" do
			:eof -> :ok
			data -> 
				element = data |> String.strip() |> String.to_integer()
				cond do
				  element < delimiter ->
				    IO.puts(element)
				  element >= delimiter -> nil
				end
				filter(delimiter)
		end
    end
end
delimiter = IO.gets("") |> String.strip |> String.to_integer
Filterlist.filter delimiter
