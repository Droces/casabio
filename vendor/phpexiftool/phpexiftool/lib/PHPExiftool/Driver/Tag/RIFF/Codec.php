<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\RIFF;

use PHPExiftool\Driver\AbstractTag;

class Codec extends AbstractTag
{

    protected $Id = 1;

    protected $Name = 'Codec';

    protected $FullName = 'RIFF::StreamHeader';

    protected $GroupName = 'RIFF';

    protected $g0 = 'RIFF';

    protected $g1 = 'RIFF';

    protected $g2 = 'Video';

    protected $Type = 'string';

    protected $Writable = false;

    protected $Description = 'Codec';

    protected $MaxLength = 4;

    protected $Index = 2;

}