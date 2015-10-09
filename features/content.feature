@api
Feature: Installation Verification
  As a Pantheor,
  I want to know that Michelle is awesome
  so that I can start to trust her work.

  Scenario: Verify that the site and its variables are installed.
    Given I am an anonymous user
    Given I am on homepage
    Then I should see the text "The Code Speaks for Itself"
