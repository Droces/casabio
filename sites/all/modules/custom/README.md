# CasaBio Custom Modules

## Table of contents

* [Organisation](#organisation)
* [Coding Standards](#coding-standards)
* [Testing](#testing)

## Organisation

At the top of PHP and JS files, there should be a file doc-block describing the contents of the file. It should look like this:

```
/**
 * @file
 * Description…
 */
```

Below the file doc-block, the contents of the file should be listed:

```
/**
 * CONTENTS
 *
 * function()
 */
```

Files that contain more than approximately 500 lines should be split into multiple files.

## Coding Standards

We follow [Drupal's coding standards](https://www.drupal.org/docs/develop/standards/coding-standards). Some more notable points (for PHP and JavaScript) include:

1. Use an indent of 2 spaces, with no tabs.
1. Lines should have no trailing whitespace at the end.
1. Statements (except `function`, `if`, loops, etc.) MUST be followed by a semi-colon (;).
1. Return values MUST start on the same line as the return keyword.

### Naming conventions

Variables and funcions should be named using lowercase, and words should be separated either with an underscore (example: $snake_case).

This does not apply to constants or constructors.

## Testing

In a terminal from the site root directory, run `phpunit`