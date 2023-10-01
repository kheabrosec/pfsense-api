<?php

namespace API\Core;

/**
 * Defines objects that execute shell commands and keep track of the output.
 */
class Command
{
    public string $command;
    public string $output = "";
    public int $result_code = -1;
    public bool $trim_whitespace = false;

    /**
     * Defines the Command object including the shell command to execute and optional modifiers. Note: By default,
     * the command output will redirect stderr to stdout so error message will be included in the output.
     * @param string $command The shell command to execute.
     * @param bool $trim_whitespace Remove excessive whitespace from the command output.
     * @return Command Returns this object containing the results of the executed command. Note: the object returned
     * cannot be used to initiate new commands. A new Command object should be created for any additional commands.
     */
    public function __construct(string $command, bool $trim_whitespace = false)
    {
        $this->command = $command;
        $this->trim_whitespace = $trim_whitespace;
        $this->run_command();
        return $this;
    }

    /**
     * Executes the assigned $command. The $output and $result_code properties will be set after running
     * this method.
     */
    private function run_command(): void
    {
        exec(command: "$this->command 2>&1", output: $raw_output, result_code: $this->result_code);
        $this->output = implode(PHP_EOL, $raw_output);

        # Normalize output's whitespace if requested
        if ($this->trim_whitespace) {
            $this->output = preg_replace('/\s+/', ' ', $this->output);
        }
    }
}