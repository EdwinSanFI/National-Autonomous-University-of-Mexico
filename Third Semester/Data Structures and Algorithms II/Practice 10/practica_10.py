import os

def run():
    cases_per_state = {}
    total_cases = 0
    gender_cases = {'M': 0, 'F': 0}
    age_cases = {}

    try:
        file = open("covid-19-mexico-01122020.csv", "r", encoding="utf-8")
        lines = file.readlines()

        # Get the data from the file
        for i in range(1, len(lines)):
            line_separated = lines[i].split(",")
            state = line_separated[1]
            total_cases += 1
            gender = line_separated[2]
            gender_cases[gender] += 1
            age = line_separated[3]
            age_cases[age] = age_cases.get(age, 0) + 1
            cases_per_state[state] = cases_per_state.get(state, 0) + 1

        # Close the file
        file.close()

        sorted_states = sorted(cases_per_state, key=cases_per_state.get, reverse=True)
        state_with_more_cases = sorted_states[0]
        state_with_less_cases = sorted_states[len(sorted_states) - 1]
        total_gender_male = gender_cases['M']
        total_gender_female = gender_cases['F']
        age_avarage = 0
        for age in age_cases.keys():
            age_avarage += int(age) * age_cases[age]
        age_avarage = age_avarage / total_cases
        minimum_age = min(age_cases.keys())
        maximum_age = max(age_cases.keys())

        if not os.path.exists("PracticaResumen"):
            os.mkdir("PracticaResumen")

        # Save the data in the file
        with open("PracticaResumen/resumenCovid.eda2", "w", encoding="utf-8") as file2:
            file2.write("\nTotal of cases: " + str(total_cases) + "\n")
            file2.write("\nState with more cases: " + state_with_more_cases + "\n")
            file2.write("\nState with less cases: " + state_with_less_cases + "\n")
            file2.write("\nTotal cases per gender:" + "\n")
            file2.write("\tMale: " + str(total_gender_male) + "\n")
            file2.write("\tFemale: " + str(total_gender_female) + "\n")
            file2.write("\nAvarage age: " + str(age_avarage) + "\n")
            file2.write("\nMinimum age: " + str(minimum_age) + "\n")
            file2.write("\nMaximum age: " + str(maximum_age) + "\n")
            file2.write("\nCases per state:" + "\n")
            for state in sorted_states:
                file2.write("\t"+state + ": " + str(cases_per_state[state]) + "\n")

    except FileNotFoundError:
        print("The file doesn't exist")

if __name__ == '__main__':
    run()