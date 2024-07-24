from flatlib.datetime import Datetime
from flatlib.geopos import GeoPos
from flatlib.chart import Chart

# Function to get planetary positions using flatlib
def get_planetary_positions_flatlib(date_of_birth, time_of_birth, latitude, longitude):
    dt = Datetime(date_of_birth, time_of_birth)
    pos = GeoPos(latitude, longitude)
    chart = Chart(dt, pos)

    planets = ['Sun', 'Moon', 'Mercury', 'Venus', 'Mars', 'Jupiter', 'Saturn', 'Uranus', 'Neptune', 'Pluto']
    positions = {}
    for planet in planets:
        planet_pos = chart.get(planet)
        positions[planet] = planet_pos.lon
    
    return positions

# Example usage
date_of_birth = '1990/07/20'  # YYYY/MM/DD
time_of_birth = '14:30'       # HH:MM
latitude = 28.6139            # Latitude for New Delhi
longitude = 77.2090           # Longitude for New Delhi

planetary_positions = get_planetary_positions_flatlib(date_of_birth, time_of_birth, latitude, longitude)

# Print the planetary positions
for planet, position in planetary_positions.items():
    print(f"{planet}: {position:.2f} degrees")
