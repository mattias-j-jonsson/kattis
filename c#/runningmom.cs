using System.IO;
using System;
using System.Collections.Generic;

class Program
{
    public class City
    {
        string name;
        List<string> destinations;
        int number_of_dest;

        public City(string name, string dest)
        {
            this.name = name;
            destinations = new List<string>();
            destinations.Add(dest);
            number_of_dest = 1;
        }

        public void addDest(string dest)
        {
            destinations.Add(dest);
            number_of_dest++;
        }

        public List<string> getDest()
        {
            return destinations;
        }

        // för list.contains
        public override bool Equals(object obj)
        {
            City objAsCity = obj as City;
            return name.Equals(objAsCity.name);
        }

        // för kunna köra contains med string
        public static implicit operator City(string name)
        {
            return new City(name, "");
        }

        public override string ToString()
        {
            string dest_string = "";
            for (int i = 0; i < destinations.Count - 1; i++)
            {
                dest_string += destinations[i] + ", ";
            }
            dest_string += destinations[destinations.Count - 1];
            return $"{name}\t {dest_string}";
        }
    }




    static void Main()
    {
        // StreamReader reader = new StreamReader("sample.in");

        // int number_of_flights = int.Parse(reader.ReadLine());
        int number_of_flights = int.Parse(Console.ReadLine());

        List<City> start_cities = new List<City>();
        for (int i = 0; i < number_of_flights; i++)
        {
            // string[] start_stop = reader.ReadLine().Split(' ');
            string[] start_stop = Console.ReadLine().Split(' ');
            if (start_cities.Contains(start_stop[0]))
            {
                int index = start_cities.IndexOf(start_stop[0]);
                start_cities[index].addDest(start_stop[1]);
            }
            else
            {
                start_cities.Add(new City(start_stop[0], start_stop[1]));
            }

        }

        List<string> cities_to_test = new List<string>();
        string temp_city;
        // while ((temp_city = reader.ReadLine()) != null)
        // {
        //     cities_to_test.Add(temp_city);
        // }
        while ((temp_city = Console.ReadLine()) != null)
        {
            cities_to_test.Add(temp_city);
        }

        foreach (string city in cities_to_test)
        {
            bool safe = false;
            List<string> visited = new List<string>();
            List<string> to_be_visited = new List<string>();
            visited.Add(city);
            if (start_cities.Contains(city) == true)
            {
                to_be_visited.AddRange(start_cities[start_cities.IndexOf(city)].getDest());
            }

            List<string> visit_temp = new List<string>();
            while (to_be_visited.Count > 0 && safe == false)
            {
                foreach (string visit_now in to_be_visited)
                {
                    if (visited.Contains(visit_now))
                    {
                        safe = true;
                        break; // ??
                    }
                    else if (start_cities.Contains(visit_now))
                    {
                        // visit_temp.AddRange(start_cities[start_cities.IndexOf(visit_now)].getDest());
                        List<string> temp_list = start_cities[start_cities.IndexOf(visit_now)].getDest();
                        foreach (string item in temp_list)
                        {
                            if (to_be_visited.Contains(item) == false)
                            {
                                visit_temp.Add(item);
                            }
                        }
                        visited.Add(visit_now);
                    }
                }
                to_be_visited.Clear();
                to_be_visited.AddRange(visit_temp);
                visit_temp.Clear();
            }

            Console.WriteLine($"{city} {(safe ? "safe" : "trapped")}");
        }
    }
}