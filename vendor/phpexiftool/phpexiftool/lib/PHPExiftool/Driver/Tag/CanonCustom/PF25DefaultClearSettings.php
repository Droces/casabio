<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\CanonCustom;

use PHPExiftool\Driver\AbstractTag;

class PF25DefaultClearSettings extends AbstractTag
{

    protected $Id = 26;

    protected $Name = 'PF25DefaultClearSettings';

    protected $FullName = 'CanonCustom::PersonalFuncs';

    protected $GroupName = 'CanonCustom';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'CanonCustom';

    protected $g2 = 'Camera';

    protected $Type = 'int16u';

    protected $Writable = true;

    protected $Description = 'PF25 Default Clear Settings';

    protected $flag_Permanent = true;

}
