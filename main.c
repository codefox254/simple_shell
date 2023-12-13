#include "shell.h"

int main(void)
{
    char *input;

    while (1)
    {
        display_prompt();
        input = read_command();
        if (!input)
            break;

        if (input[0] != '\0')
        {
            trim_whitespace(input);

            if (input[0] != '\0')
            {
                char *tokens[MAX_INPUT];
                tokenize_string(input, tokens);

                if (tokens[0] != NULL)
                {
                    if (strcmp(tokens[0], "exit") == 0)
                    {
                        free(input);
                        free_tokens(tokens);
                        break;
                    }

                    handle_builtin(tokens[0], tokens);

                    for (int i = 1; tokens[i] != NULL; i++)
                    {
                        if (strcmp(tokens[i], "<") == 0)
                        {
                            handle_input_redirection(tokens[0], tokens[i + 1]);
                            tokens[i] = NULL;
                        }
                        else if (strcmp(tokens[i], ">") == 0)
                        {
                            handle_output_redirection(tokens[0], tokens[i + 1]);
                            tokens[i] = NULL;
                        }
                    }

                    execute_command(tokens[0], tokens);
                }

                free_tokens(tokens);
            }
        }

        free(input);
    }

    return 0;
}

